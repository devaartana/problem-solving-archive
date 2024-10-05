class Solution {
public:
    vector<int> constructRectangle(int area) {
        if(area > 3 ) {
            for(int i = sqrt(area); i <= area; i++){
                if(!(area%i)) {
                    if(area/i > i) {
                        return {area/i, i};
                    }

                    return {i, area/i};
                }
            }
        }

        return {area, 1};
    }
};