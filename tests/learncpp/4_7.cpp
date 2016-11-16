#include <iostream>

struct Advertising{
    int32_t totalAds;
    double clickedAds;
    double averageEarning;
};

void printAdvertising(Advertising mySite)
{
    std::cout << "total ads: " << mySite.totalAds << "\n" <<
                 "clicked ads: " << mySite.clickedAds << "\n" <<
                 "Average Earnings: " << mySite.clickedAds << "\n";

    double total = mySite.totalAds * mySite.clickedAds * mySite.averageEarning;
    std::cout << "Total earnings: " << total << "\n";
}

int main()
{
    Advertising mySite;

    std::cout << "Total showing Ads: \n";
    std::cin >> mySite.totalAds;

    std::cout << "Out of them how many where clicked: \n";
    std::cin >> mySite.clickedAds;

    std::cout << "Average earnings: \n";
    std::cin >> mySite.averageEarning;

    printAdvertising(mySite);
}
