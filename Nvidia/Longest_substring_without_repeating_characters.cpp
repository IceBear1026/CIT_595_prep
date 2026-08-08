class Solution {
public:
/*
KEY IDEA I FINALLY UNDERSTOOD:

This is a SLIDING WINDOW problem because we are looking for a CONTIGUOUS substring.

The main idea is that we keep one current valid window between left and right.
That window should always contain NO duplicate characters.

The set is not just storing random unique characters.
It is supposed to represent the characters that are inside my CURRENT CONTIGUOUS WINDOW.

So basically:

left = where my current substring/window starts.
right = the next character I am trying to add into the window.
unique_chars = all the characters currently inside that window.
longest_length = the biggest valid window I have seen so far.

We keep moving right forward because we want to make the substring bigger and bigger.

If s[right] is NOT already inside the set:
- That means adding it still keeps the substring unique.
- So we insert it into the set.
- We compare the current window size with longest_length.
- Then we move right forward and try to make the window even bigger.

BUT if s[right] is already in the set:
- That means adding this character would create a duplicate.
- So our current window cannot grow yet.
- We need to SHRINK the window from the LEFT side.

This is why we do:

unique_chars.erase(s[left]);
left++;

We are basically saying:
"Remove the leftmost character from my current contiguous substring and move
the starting point of the substring forward."

IMPORTANT:
We do NOT move right when we find a duplicate.

Why?

Because we still have not successfully added s[right] yet.
We shrink from the left and then check that SAME right character again.

Example:

s = "xyzxz"

At first:

window = "xyz"
set = {x, y, z}

Then right reaches the second x:

"xyzx"
^

x is already inside the set, so this would be invalid.

We remove from the LEFT:

remove x
window becomes "yz"
set becomes {y, z}
left moves forward

RIGHT DOES NOT MOVE.

Now we check the same second x again.

x is no longer in the set, so now we can add it:

window = "yzx"
set = {y, z, x}

Then right moves again.

Next we reach the second z.

Current window:

"yzx"

z is already inside it.

So we shrink from the left:

remove y
window = "zx"

But z is STILL duplicated because the old z is still inside the window.

So we shrink again:

remove old z
window = "x"

Now the new z is safe to add:

window = "xz"

This is the part that made sliding window make sense to me:

We are always keeping a CONTIGUOUS valid substring.

Instead of restarting completely every time we find a duplicate, we reuse the
part of the previous substring that is still valid.

Brute force would basically restart from every index and check every possible
substring.

Sliding window is smarter because it says:

"I already know part of my previous window is still valid, so I will just move
the left side forward until the window becomes valid again."

So the general feeling for sliding window is:

expand RIGHT when the window is valid
shrink LEFT when the window becomes invalid

For this specific problem:

VALID = no duplicate characters

The main invariant is:

unique_chars should always represent exactly the characters currently inside
the contiguous window between left and right - 1.

That is the real reason why we remove s[left] and increment left.

We are not removing characters randomly.
We are changing where our current contiguous substring starts.
*/
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> unique_chars;
        int left = 0;
        int right = 0;
        int longest_length = 0;

        // while loop until the right hits the right most character within the string. 
        while(right < s.size()) {
            if(!unique_chars.contains(s[right])){
                unique_chars.insert(s[right]);
                longest_length = max((int)unique_chars.size(), longest_length);
                right++;
            } else {
                unique_chars.erase(s[left]);
                left++;
            }
            
        }
        return longest_length;
    }
};
