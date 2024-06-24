/*
** EPITECH PROJECT, 2022
** droid
** File description:
** droid
*/

class Droid {
private:
    std::string Id;
    size_t Energy;
    const size_t Attack = 25;
    const size_t Toughness = 15;
    std::string *Status = new std::string("Standing by");
public:
    Droid();
    Droid(const Droid& d);
    Droid(std::string x);
    void setStatus(std::string *s);
    void setId(std::string s);
    void setEnergy(size_t s);
    std::string getId() const;
    size_t getEnergy() const;
    size_t getAttack ();
    size_t getToughness();
    std::string getStatus() const;
    Droid& operator=(const Droid& d);
    size_t operator!=(const Droid& d);
    size_t operator==(const Droid& d);
    void operator<<(size_t &d);
    ~Droid();
};

std::ostream& operator<<(std::ostream& os, const Droid& dt);
