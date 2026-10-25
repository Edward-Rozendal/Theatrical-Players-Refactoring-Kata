#include "statement.h"

#include <iostream>
#include <sstream>
#include <iomanip>

int totalVolumeCredits(
    const nlohmann::json& invoice,
    const nlohmann::json& plays);

int volumeCreditsFor(
    const nlohmann::json& play,
    const nlohmann::json& performance);

nlohmann::json playFor(
    const nlohmann::json& plays,
    const nlohmann::json& performance);
    
float amountFor(
    const nlohmann::json& play,
    const nlohmann::json& perf);


// https://stackoverflow.com/a/7277333/104370
class comma_numpunct : public std::numpunct<char>
{
  protected:
    virtual char do_thousands_sep() const override
    {
        return ',';
    }

    virtual std::string do_grouping() const override
    {
        return "\03";
    }
};

std::string statement(
    const nlohmann::json& invoice,
    const nlohmann::json& plays)
{
    // this creates a new locale based on the current application default
    // (which is either the one given on startup, but can be overriden with
    // std::locale::global) - then extends it with an extra facet that
    // controls numeric output.
    const std::locale comma_locale(std::locale(), new comma_numpunct());

    std::stringstream result;
    result.imbue(comma_locale);
    result.precision(2);
    result << "Statement for " << invoice["customer"].get<std::string>() << '\n';

    for( const nlohmann::json& perf : invoice["performances"])
    {
        // print line for this order
        result << " " << playFor(plays, perf)["name"].get<std::string>() << ": " << "$" << std::fixed << (amountFor(playFor(plays, perf), perf)/100) <<
            " (" << perf["audience"] << " seats)\n";
    }
    float total_amount = 0;
    for( const nlohmann::json& perf : invoice["performances"])
    {
        total_amount += amountFor(playFor(plays, perf), perf);
    }

    result << "Amount owed is " << "$" << std::fixed << (total_amount/100.0f) << "\n";
    result << "You earned " << totalVolumeCredits(invoice, plays) << " credits";
    return result.str();
}

int totalVolumeCredits(
    const nlohmann::json& invoice,
    const nlohmann::json& plays)
{
    int result = 0;
    for( const nlohmann::json& perf : invoice["performances"])
    {
        result += volumeCreditsFor(playFor(plays, perf), perf);
    }
    return result;
}

int volumeCreditsFor(
    const nlohmann::json& play,
    const nlohmann::json& performance)
{
    // add volume credits
    int result = std::max(performance["audience"].get<int>() - 30, 0);

    // add extra credit for every ten comedy attendees
    if ("comedy" == play["type"])
    {
        result += performance["audience"].get<int>() / 5;
    }
    return result;
}

nlohmann::json playFor(
    const nlohmann::json& plays,
    const nlohmann::json& performance)
{
    return plays[performance["playID"].get<std::string>()];
}

float amountFor(
    const nlohmann::json& play,
    const nlohmann::json& performance)
{
    float result = 0;
    if (play["type"] == "tragedy")
    {
        result = 40000;
        if (performance["audience"] > 30)
        {
            result += 1000 * (performance["audience"].get<int>() - 30);
        }
    }

    else if (play["type"] == "comedy")
    {
        result = 30000;
        if (performance["audience"] > 20)
        {
            result += 10000 + 500 * (performance["audience"].get<int>() - 20);
        }

        result += 300 * performance["audience"].get<int>();
    }

    else
    {
        throw std::domain_error("unknown type: " + play["type"].get<std::string>());
    }
    return result;
}
