class Solution {
public:
    vector<int> constructRectangle(int area) {
        int i;
        for(i = sqrt(area); area%i; i--);
        return {area/i, i};
    }
};