#include <iostream>

class Phone
{
private:
    int model, ram, cam_res;

public:
    bool headphoneSupport;
    Phone()
    {
        model = 10000;
        ram = 8;
        cam_res = 32;
        headphoneSupport = true;
    }
    Phone(int mod, int r, int c_res, bool headSupport)
    {
        model = mod;
        ram = r;
        cam_res = c_res;
        headphoneSupport = headSupport;
    }
    int getModel()
    {
        return model;
    }
    int getRam()
    {
        return ram;
    }
    int getCamRes()
    {
        return cam_res;
    }
    void printDetails()
    {
        std::cout<<std::boolalpha;
        std::cout << "\nModel = " << model << "\nRam = " << ram << "\nCamera Resolution = " << cam_res << "\nHeadphone Supprt = " << headphoneSupport << std::endl;
    }
    //* Destructor
    ~Phone(){
    }
};

int main()
{
    //* Custom Constructor
    Phone samA50;
    std::cout<<"\nFor No Parameter Contructor"<<std::endl;
    samA50.printDetails();
    //* Paramertarised Constructor
    Phone iPhoneX(1, 4, 12, false);
    std::cout<<"\nFor Parameter Contructor"<<std::endl;
    iPhoneX.printDetails();
    return 0;
}