#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

enum class Ordertype{
    FillAndKill,
    GoodtillCancel

};

enum class Side{
    Buy,
    Sell
};

using Price int32_t;
using Qty uint32_t;
using OrderId uint32_t;

struct LevelInfo{
    Price price_;
    Qty qty_;
};

using LevelInfos = std::vector<LevelInfo>;

Class OrderBookLevelInfos
{
public:
    OrderBooklevelInfos(const LevelInfos& bids_,const LevelInfos& asks_)
        :bids_{ bids}
        asks_{ asks }
        ,
        {}
        const LevelInfos& GetBids() const { return bids_;}
        const LevelInfos& GetAsks() const { return asks_;}
private:
    LevelInfos bids_;
    LevelInfos asks_; 
};

class Order
{
public:
    Order(OrderType orderType, OrderSide orderSide, OrderId orderId, Price price, OrderQty orderQty)
    :orderType_{ orderType }, 
    orderSide_{ orderSide }, 
    orderId_{ orderId }, 
    price_{ price }, 
    initialOrderQty_{ orderQty },
    remainingOrderQty_{ orderQty },
    {}

    OrderType GetOrderType() const { return orderType_; }
    OrderSide GetOrderSide() const { return orderTSide_; }
    OrderId GetOrderID() const { return orderId_; }
    Price GetPrice() const { return Price_; }
    OrderQty GetRemainingOrderQty() const { return remainingOrderQty_; }
    OrderQty GetInitialOrderQty() const { return initialOrderQty_; }
    OrderQty GetFilledOrderQty() const { return GetInitialOrderQty()-GetRemainingOrderQty(); }

    void Fill(OrderQty orderQty){
        if(orderQty>getRemainingOrderQty){
            throw std::logic_error(std::format("Order ({}) cannot be filled for more than its remaining quantity", GetOrderID()));
        }
        remainingOrderQty -= orderQty;
    }

private:
    OrderType orderType_;
    OrderSide orderSide_;
    OrderId orderId_;
    Price price_;
    OrderQty remainingOrderQty_;
    OrderQty initialOrderQty_;
}


using OrderPointer = std::shared_ptr<Order>;
using OrderPointers = std::list<OrderPointer>;
int main()
{
 return 0;
}


