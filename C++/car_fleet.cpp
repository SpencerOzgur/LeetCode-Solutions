class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        vector<pair<int, int>> cars;

        for (int i=0; i<position.size(); i++){
            pair<int, int> p = {position[i], speed[i]};
            cars.push_back(p);
        }

        sort(cars.begin(), cars.end(), greater<>());

        for (auto& [p, s] : cars){
            st.push((double) (target - p) / s);

            if (st.size() > 1){
                double temp = st.top();
                st.pop();
                double second = st.top();
                st.push(temp);

                if (st.top() <= second){
                    st.pop();
                }
            }
        }
        return st.size();
    }
};
