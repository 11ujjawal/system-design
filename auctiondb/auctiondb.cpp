#include <iostream>
#include <fstream>
#include "auctiondb.hpp"

/**
 *
 */
void AuctionDB::setAssetType(std::string assetTypeName) {
    assetTypes.insert(assetTypeName);
}

void AuctionDB::setAssetItem(std::string assetTypeName, std::string assetItemName) {
    assetItems[assetTypeName].insert(assetItemName);
}

const std::set<std::string>& AuctionDB::getAssetTypes() {
    return assetTypes;
}

const std::set<std::string>& AuctionDB::getAssetItems(std::string assetTypeName) {
    return assetItems[assetTypeName];
}

Bid AuctionDB::getMaxBid(std::string assetTypeName, std::string assetItemName) {
    return data[assetTypeName][assetItemName].top();
}

void AuctionDB::addAsset(std::string assetTypeName, std::string assetItemName, Bid bidvalue) {
    data[assetTypeName][assetItemName].push(bidvalue);
    assetTypes.insert(assetTypeName);
    assetItems[assetTypeName].insert(assetItemName);
}

bool operator<(const Bid& bidOne, const Bid& bidTwo) {
    return bidOne.price < bidTwo.price;
}

std::ostream& operator<<(std::ostream& out, const Bid& value) {
    out << "Name: " << value.username << std::endl << "Bid: " << value.price << std::endl;
    return out;
}

std::istream& operator>>(std::istream& input, Bid& value) {
    input >> value.username;
    input >> value.price;
    return input;
}

void AuctionDB::setAssetBid(std::string filename) {
    std::ifstream file(filename);
    std::string assetTypeName, assetTypeItem;
    Bid bidvalue;

    while(file >> assetTypeItem >> assetTypeName >> bidvalue) {
        addAsset(assetTypeName, assetTypeItem, bidvalue);
    }
}

void AuctionDB::getAssetBid() {
    const std::set<std::string>& assetTypeNames = getAssetTypes();

    std::cout << "Auction item categories - " << std::endl;
    for(std::set<std::string>::iterator aType = assetTypeNames.begin(); aType != assetTypeNames.end(); ++aType)
        std::cout << *aType << std::endl;

    std::string assetTypeName;
    std::cin >> assetTypeName;

    const std::set<std::string>& assetItemNames = getAssetItems(assetTypeName);

    std::cout << "Auction items - " << std::endl;
    for(std::set<std::string>::iterator aName = assetItemNames.begin(); aName != assetItemNames.end(); ++aName)
        std::cout << *aName << std::endl;

    std::string assetItemName;
    std::cin >> assetItemName;

    Bid maxBid = getMaxBid(assetTypeName, assetItemName);
    std::cout << "Maximum Bid - \n" << maxBid;
}
