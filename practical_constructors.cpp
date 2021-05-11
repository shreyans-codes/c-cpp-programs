#include <iostream>

class Phone
{
    //* Default Constructor
    private:
    int model, ram, cam_res;
    public:
    bool headphoneSupport;
    void setDetails(int mod, int r, int c_res){
        model = mod;
        ram = r;
        cam_res = c_res;
    }
    int getModel() {
        return model;
    }
    int getRam() {
        return ram;
    }
    int getCamRes() {
        return cam_res;
    }
    void printDetails() {
        std::cout<<std::boolalpha;
        std::cout<<"\nModel = "<<model<<"\nRam = "<<ram<<"\nCamera Resolution = "<<cam_res<<"\nHeadphone Supprt = "<<headphoneSupport<<std::endl;
    }
};


int main(){
    Phone miNote9;
    miNote9.printDetails();
    return 0;
}