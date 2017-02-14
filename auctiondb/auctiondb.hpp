#ifndef _AUCTIONDB_HPP
#define _AUCTIONDB_HPP

#include <unordered_map>
#include <string>
#include <queue>
#include <set>

struct Bid {
    std::string username;
    unsigned price;

    Bid() = default;
    Bid(std::string uname, unsigned quote) : username(uname), price(quote) {}

    bool operator<(const Bid& value) {
        return price < value.price;
    }
};

class AuctionDB {
    std::unordered_map<std::string, std::unordered_map<std::string, std::priority_queue<Bid> > > data;
    std::set<std::string> assetTypes;
    std::unordered_map<std::string, std::set<std::string> > assetItems;

    void setAssetType(std::string assetTypeName);
    void setAssetItem(std::string assetTypeName, std::string assetItemName);

    const std::set<std::string>& getAssetTypes();
    const std::set<std::string>& getAssetItems(std::string assetTypeName);

    void addAsset(std::string assetTypeName, std::string assetItemName, Bid bidvalue);
    Bid getMaxBid(std::string assetTypeName, std::string assetItemName);

public:
    void setAssetBid(std::string filename);
    void getAssetBid();
};

#endif
