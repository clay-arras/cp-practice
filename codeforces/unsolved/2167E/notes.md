

probably a binary search
we binary search over the minimum time, call it D. 
lets sort the start positions

define GOOD intervals as intervals that are at least D away from the nearest friend

you can use a line sweep or anything else to process intervals
lets also store an answer array as a global variable

have a prev_good_interval
