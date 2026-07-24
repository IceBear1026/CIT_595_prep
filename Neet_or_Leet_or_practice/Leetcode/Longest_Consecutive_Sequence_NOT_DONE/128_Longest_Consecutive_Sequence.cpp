class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // "vector.empty() is an easy way to check if a vector is empty."
        if (nums.empty()) return 0;

        set<int> sets(nums.begin(), nums.end());

        // since we know it's more than 0 since it's not empty let's start with 1. 
        int longest = 1;
        int current = 1;

        // we are setting "prev" as our beginning iterator value.
        auto prev = sets.begin();
        // this "next()" is a way to to get an iterator that is advanced forward without changing the original iterator.
        auto it = next(prev);

        /*
        so from the above *prev is the current value and *it is the next value. 
        */

        // This iterator is currently pointing to a valid element, not the special past-the-end position
        // sets.end() is not the last value. It is a special iterator that points one position after the last element.

        /*
        For example:
        set<int> sets = {1, 2, 3};

        Conceptually:

        1   2   3   end
        ^
        begin()

        ===
        auto it = sets.begin(); // points to 1
        ++it;                   // points to 2
        ++it;                   // points to 3
        ++it;                   // now equals sets.end()
        */

        /*
        For checking whether a value exists in the set, you usually use:

        if (sets.find(100) != sets.end()) {
            // 100 exists in the set
        }

        ===
        So there are two related but different meanings:

        it != sets.end()

        means this iterator is valid and points to an element.

        sets.find(value) != sets.end()

        means that specific value was found in the set.
        */

        // so basically it just means if the next element isn't the end special iterator object, keep looping.
        while (it != sets.end()){
            // checking the actual value + 1
            if (*it == *prev + 1){
                current ++;
            }
            else {
                current = 1;
            }

            // max() is an easy way to check the values of which one is larger.
            longest = max(longest, current);

            /*
            prev = it does not move anything forward. 
            it only makes prev poing to the same element that it currently points to. 
            the line that actually moves forward is:
            ++it;

            And yes, even though it is an iterator, ++it is the normal way to move an iterator to the next element. 

            Suppose the set is:
            {1, 2, 3, 4, 100, 101}

            At some point:

            prev
            |
            v
            1   2   3   4   100   101   end
                ^
                |
                it

            So:

            *prev == 1
            *it   == 2

            prev = it;
            ++it;

            After:

            prev = it;

            both point to 2:

                prev
                |
                v
            1   2   3   4   100   101   end
                ^
                |
                it

            Then:

            ++it;

            moves only it forward:

                prev
                |
                v
            1   2   3   4   100   101   end
                    ^
                    |
                    it

            Now you are ready to compare:

            *prev == 2
            *it   == 3
            */

            // I get it now. So "prev = it" IS ACTUALLY pushing one up by setting to same pointer in the set as "it".
            // ++it is pushing one up JUST FOR "it" itself.
            prev = it;
            ++it;
        }
    return longest;
    }
};