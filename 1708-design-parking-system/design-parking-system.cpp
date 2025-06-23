class ParkingSystem {
    private:
    int bigSlot;
    int medSlot;
    int smallSlot;
public:
    ParkingSystem(int big, int medium, int small) {
        bigSlot = big;
        medSlot = medium;
        smallSlot = small;
    }
    
    bool addCar(int carType) {
        switch(carType){
            case 1:
                if(bigSlot != 0){
                    bigSlot--;
                    return true;
                }
                else
                    return false;
            case 2:
                if(medSlot != 0){
                    medSlot--;
                    return true;
                }
                else
                    return false;
            case 3:
                if(smallSlot != 0){
                    smallSlot--;
                    return true;
                }
                else
                    return false;
            default:
                return false;
        }
        
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */