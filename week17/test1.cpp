
//定义 Quote 和 Bulk_quote 的拷贝控制成员，令其与合成的版本行为一致。
//为这些成员以及其他构造函数添加打印状态的语句，使得我们能够知道正在运行哪个程序。
//使用这些类编写程序，预测程序将创建和销毁哪些对象。
//重复实验，不断比较你的预测和实际输出结果是否相同，直到预测完全准确再结束。


#include<iostream>
#include<string>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) :
        bookNo(book), price(sales_price) {
            std::cout<<"Quote(const std::string &book, double sales_price)"
                <<std::endl;
        }
    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const;
    virtual ~Quote() {std::cout<<"~Quote()"<<std::endl; }
    virtual std::ostream & debug(std::ostream & os) const;

    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {
        std::cout << "Quote(const Quote &q)" << std::endl;  }
    Quote(Quote && q) : bookNo(std::move(q.bookNo)),  price(std::move(q.price)) {
                std::cout << "Quote(Quote && q)" << std::endl; }
    Quote & operator=(const Quote &);
    Quote & operator=(Quote &&);

private:
    std::string bookNo;

protected:
    double price = 0.0;
};

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string & book, double price,
        std::size_t qty, double disc) :
        Quote(book, price), quantity(qty), discount(disc) {
            std::cout<<"Disc_quote(const std::string & book, double price,"
               <<"std::size_t qty, double disc) "<<std::endl;
        }

    std::ostream & debug(std::ostream & os) const override;
    double net_price(std::size_t) const override= 0;

    Disc_quote(const Disc_quote &q) :
        Quote(q), quantity(q.quantity), discount(q.discount) {
            std::cout << "Disc_quote(const Disc_quote &q)" << std::endl; }
    Disc_quote(Disc_quote && q) :
        Quote(std::move(q)), quantity(std::move(q.quantity)),
        discount(std::move(q.discount)) {
            std::cout << "Disc_quote(Disc_quote && q)" << std::endl; }
    Disc_quote & operator=(const Disc_quote &);
    Disc_quote & operator=(Disc_quote &&);
    ~Disc_quote()
    {
        std::cout << "~Disc_quote()"<<std::endl;
    }


protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string & book, double price,
            std::size_t qty, double disc) :
        Disc_quote(book, price, qty, disc) {
            std::cout<<"Bulk_quote(const std::string & book,"<<
            "double price, std::size_t qty, double disc) "<<std::endl; }

    double net_price(std::size_t) const override;

    Bulk_quote(const Bulk_quote &q) : Disc_quote(q) {
        std::cout << "Bulk_quote(const Bulk_quote &q)" << std::endl; }
    Bulk_quote(Bulk_quote && q) : Disc_quote(std::move(q)) {
        std::cout << "Bulk_quote(Bulk_quote && q)" << std::endl; }
    Bulk_quote & operator=(const Bulk_quote &);
    Bulk_quote & operator=(Bulk_quote &&);

    ~Bulk_quote() override
    {
        std::cout << "~Bulk_quote() "<<std::endl;
    }
};

double print_total(std::ostream & os, const Quote & item, std::size_t cnt);

double Quote::net_price(std::size_t n) const
{
    return n * price;
}

double print_total(std::ostream & os, const Quote & item, std::size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << std::endl;
    return ret;
}

double Bulk_quote::net_price(std::size_t cnt) const
{
    if(cnt >= quantity)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

std::ostream & Quote::debug(std::ostream & os) const
{
    os << bookNo << " " << price;
    return os;
}

std::ostream & Disc_quote::debug(std::ostream & os) const
{
    Quote::debug(os) << " " << quantity << " " << discount;
    return os;
}

Quote & Quote::operator=(const Quote & rhs)
{
    std::cout << "Quote & Quote::operator=(const Quote & rhs)" << std::endl;
    bookNo = rhs.bookNo;
    price = rhs.price;
    return *this;
}

Quote & Quote::operator=(Quote && rhs)
{
    std::cout << "Quote & Quote::operator=(Quote && rhs)" << std::endl;
    bookNo = std::move(rhs.bookNo);
    price = std::move(rhs.price);
    return *this;
}

Disc_quote & Disc_quote::operator=(const Disc_quote & rhs)
{
    Quote::operator=(rhs);
    std::cout << "Disc_quote & Disc_quote::operator=(const Disc_quote & rhs)"
        << std::endl;
    quantity = rhs.quantity;
    discount = rhs.discount;
    return *this;
}

Disc_quote & Disc_quote::operator=(Disc_quote && rhs)
{
    Quote::operator=(std::move(rhs));
    std::cout << "Disc_quote & Disc_quote::operator=(Disc_quote && rhs)" <<
        std::endl;
    quantity = rhs.quantity;
    discount = rhs.discount;
    return *this;
}

Bulk_quote & Bulk_quote::operator=(const Bulk_quote & rhs)
{
    Disc_quote::operator=(rhs);
    std::cout << "Bulk_quote & Bulk_quote::operator=(const Bulk_quote & rhs)"
        << std::endl;
    return *this;
}

Bulk_quote & Bulk_quote::operator=(Bulk_quote && rhs)
{
    Disc_quote::operator=(std::move(rhs));
    std::cout << "Bulk_quote & Bulk_quote::operator=(Bulk_quote && rhs)"
        << std::endl;
    return *this;
}
int main()
{
    Bulk_quote b("abc",1,1,1);
    Bulk_quote b2(b);//Bulk_quote b2=b;
    b=b2;
    b=std::move(b2);
    return 0;
}
//Quote(const std::string &book, double sales_price)
//Disc_quote(const std::string & book, double price,std::size_t qty, double disc)
//Bulk_quote(const std::string & book,double price, std::size_t qty, double disc)
//Quote(const Quote &q)
//Disc_quote(const Disc_quote &q)
//Bulk_quote(const Bulk_quote &q)
//Quote & Quote::operator=(const Quote & rhs)
//Disc_quote & Disc_quote::operator=(const Disc_quote & rhs)
//Bulk_quote & Bulk_quote::operator=(const Bulk_quote & rhs)
//Quote & Quote::operator=(Quote && rhs)
//Disc_quote & Disc_quote::operator=(Disc_quote && rhs)
//Bulk_quote & Bulk_quote::operator=(Bulk_quote && rhs)
//~Bulk_quote()
//~Disc_quote()
//~Quote()
//~Bulk_quote()
//~Disc_quote()
//~Quote()

