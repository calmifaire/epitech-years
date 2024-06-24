/*
** EPITECH PROJECT, 2022
** DroidMemory
** File description:
** memo
*/

class DroidMemory{
private:
    size_t Fingerprint;
    size_t Exp;
public:
    DroidMemory();
    size_t getFingerprint() const;
    size_t getExp() const;
    void setFingerprint(size_t F);
    void setExp(size_t E);
    void operator<<(DroidMemory const d);
    void operator>>(DroidMemory &d);
    void operator+=(DroidMemory const d);
    void operator+=(size_t d);
};

std::ostream& operator<<(std::ostream& os, const DroidMemory& dt);
