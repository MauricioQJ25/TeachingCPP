#include <iostream>
#include <memory>

class Talker{
    public:
        explicit Talker (std::string name) : name_(std::move(name)){
        std::cout << name_ << " here.\n";
    }
    ~Talker() {
        std::cout << name_ << ", signing off.\n";
    }

    private:
        std::string name_;
};

int main(){
    Talker* nushi = new Talker("Nushi");

    // The std::unique_ptr calls delete for us

    std::unique_ptr<Talker> jose = std::make_unique<Talker>("Jose");

    // We can't forget to call 'delete' because we called 'new'!
    delete nushi;
}