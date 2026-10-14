
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;

        int left = 0;
        int res = 0;
        //   0 1 2 0
        //s="a b b a"

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            if(lastSeen.count(c) && lastSeen[c] >= left){
                left = lastSeen[c] + 1;
            }

            lastSeen[c] = right;
            res = max(res, right - left + 1);



            /*
            okay at this problem im cooked i give up and see the solutiohn 
            and i feel bad about that cuz it's realy was easy to solve 
            but let's forget it now and try to implement the solution 
            now we will play with indexies 
            we will cal the last index that the char appear then we will store it 
            at our hash map 
            now the same char appear so now i will move our left one move
            and then calc the longest substring and update the last seen for the current 
            char now with this way i can with linear time to get all possible undublicated
            stirngs and in our res variable we will only keep the largest or longest substring baby ;)
            now let's cook
            
            */
        }

        return res;
    }
};
