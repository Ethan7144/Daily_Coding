class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int distance = 0;
        int maxDistance = 0;
        bool isStart = true;

        for(int i = 0; i < seats.size(); ++i){

            if(seats[i] == 1 && isStart){
                maxDistance = distance;
                distance = 0;
                isStart = !isStart;
            }
            if(seats[i] == 1 && distance > maxDistance){
                if(!isStart){
                    int temp = distance;
                    if(temp % 2 == 1)
                    {
                    temp = (distance / 2) + 1;
                    }
                    else if(temp % 2 == 0){
                        temp = distance /2;
                    }
                    if(temp > maxDistance){
                        maxDistance = temp;
                        temp = 0;
                    }
                    
                }
                distance = 0;
            }
            else if(seats[i] == 1){
                distance = 0;
            }
            if(seats[i] == 0){
                distance++;
            }
        }
                if(distance > maxDistance){
            maxDistance = distance;
        }
        return maxDistance;

        }

};