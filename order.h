
// Order class representing individual orders
class Order{
    
public:
    enum class OrderType { Market, Limit, Stop, GoodTillCanceled, FillOrKill_Limit};
    enum class Side { Buy, Sell };
    // Constructor to initialize an order
    Order(int id, OrderType type, Side side, double price, int quantity)
        : id(id), type(type), side(side), price(price), quantity(quantity) {}

    // Getter methods for order attributes
    int getId() const { return id; }
    OrderType getType() const { return type; }
    Side getSide() const { return side; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    // Method to update order quantity
    void setQuantity(int new_quantity) { quantity = new_quantity; }

private:
    int id;
    OrderType type;
    Side side;
    double price;
    int quantity;
};

