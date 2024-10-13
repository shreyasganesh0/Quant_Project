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
    initialQty_{ orderQty },
    remainingQty_{ orderQty },
    {}

    OrderType GetOrderType() const { return orderType_; }
    OrderSide GetOrderSide() const { return orderTSide_; }
    OrderId GetOrderID() const { return orderId_; }
    Price GetPrice() const { return Price_; }
    OrderQty GetRemainingQty() const { return remainingQty_; }
    OrderQty GetInitialQty() const { return initialQty_; }
    OrderQty GetFilledQty() const { return GetInitialQty()-GetRemainingQty(); }
    bool IsFilled() const{ return GetRemainingQty() == 0;}
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

class OrderModify{
    public:
    OrderModify(OrderId orderID, Side side, Price price, Qty qty):
        orderId_{ orderId},
        side_{ side },
        price_{ price},
        qty_{ qty}
    {}
    OrderId GetOrderId() const { return orderId_};
    Side GetSide() const{ return side_};
    Price GetPrice() const{ return price_};
    Qty GetQty() const {return qty_};

    OrderPointer ToOrderPointer(OrderType type) const
    {
        return std::make_shared<Order>(type, GetOrderId(), GetSide(), GetPrice(), GetQty());
    }
    
    private:
    OrderId orderId_;
    Price price_;
    Side side_;
    Qty qty_;

}

struct TradeInfoObject{
    OrderId orderId_;
    Price price_;
    Qty qty_;
}

class Trade{
    public:
    Trade(const TradeInfo& bidTrade, const TradeInfo& askTrade):
        bidTrade_{ bidTrade},
        askTrade_{ askTrade }
    {}

    const TradeInfo& GetBidTrade() const{ return bidTrade_;}
    const TradeInfo& GetAskTrade() const{ return askTrade_;}


}

using Trades = std::vector<Trade>

class OrderBook{
    private:

    struct OrderEntry{
        OrderPointer order_{ nullptr};
        OrderPointers::iterator location;

        std::map<Price, OrderPointers, std::greater<Price>> bids_; 
        std::map<Price, OrderPointers, std::lesser<Price>> asks_;
        std::unordered_map<OrderId, OrderEntry> orders_;

        bool CanMatch(Side side, Price price){
            if (side == Side::Buy){
                if asks_.Empty(){
                    return false;
                    
                    const auto& [bestAsk, _]= *asks_.begin();
                    return price >= bestAsk;
                }
            }
            else{
                if bids_.Empty(){

                    return false;

                    const auto& [bestBid, _] = *bids_.begin();
                    return price<= bestBid;

                }

                    
                }

            }
        
        Trades MatchOrders()
        {
            Trades trades;
            trades.reserve(orders_.size());

            while (true){
                if (bids_.empty() || asks_.empty())
                    break;
                
                auto& [bidPrice, bids]= *bids_.begin();
                auto& [askPrice, asks]= *asks_.begin();

                if (bidPrice<askPrice)
                    break;

                while(bids.size() && asks.size()){

                    auto& bid= bids.front();
                    auto& ask= asks.front();

                    Qty qty = std::min(ask -> GetRemainingQty, bid -> GetRemaningQty);

                    bid->FillQty();
                    ask->FillQty();

                    if(bid -> IsFilled()){
                        bids.pop_front();
                        orders_.erase(bid -> GetOrderId())

                    }

                    if(ask -> IsFilled()){
                        asks.pop_front();
                        orders_.erase(ask -> GetOrderId())
                        
                    }


                }


                
            }
        }



    }
int main()
{
 return 0;
}


