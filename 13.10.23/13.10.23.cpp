#include <iostream>
#include <string>
#include <vector>

class Tariff {
public:
    Tariff(int id, const std::string& name, double price, int length)
        : id(id), name(name), price(price), length(length) {}

    int getId() const { return id; }
    const std::string& getName() const { return name; }
    double getPrice() const { return price; }
    int getLength() const { return length; }

private:
    int id;
    std::string name;
    double price;
    int length;
};

class Subscription {
public:
    Subscription(int id, class User* user, class Tariff* tariff);
    ~Subscription();
    void Extend(int length);

private:
    int id;
    class User* user;
    class Tariff* tariff;
    int endDate;
};

class User {
public:
    User(int id, const std::string& name, int age, const std::string& gender);
    int getId() const;
    const std::string& getName() const;
    void Unsubscribe(Subscription* sub);

private:
    int id;
    std::string name;
    int age;
    std::string gender;
    std::vector<Subscription*> subscriptions;
};

Subscription::Subscription(int id, User* user, Tariff* tariff)
    : id(id), user(user), tariff(tariff) {
    int now = 0;
    endDate = now + tariff->getLength();
}

Subscription::~Subscription() {
    std::cout << "Подписка " << id << " была продлена на " << endDate << " месяцев и затем удалена." << std::endl;
}

void Subscription::Extend(int length) {
    endDate += length;
}

User::User(int id, const std::string& name, int age, const std::string& gender) {
    this->id = id;
    this->name = name;
    this->age = age;
    this->gender = gender;
}

int User::getId() const {
    return id;
}

const std::string& User::getName() const {
    return name;
}

void User::Unsubscribe(Subscription* sub) {
    delete sub;
}

int main() {
    Tariff* basicTariff = new Tariff(1, "Базовый", 10.99, 1);
    User* user1 = new User(1, "Иван", 25, "Мужской");
    Subscription* subscription1 = new Subscription(1, user1, basicTariff);

    subscription1->Extend(3);

    delete basicTariff;
    delete user1;

    return 0;
}
