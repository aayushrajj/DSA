we stay on the boundary and for each cell , if we find it to be 'o' then we change it to '#' and keep going inwards (dfs) and keep changing 'o's to '#'s and and return as soon as we meet first 'x'
​
then we traverse through inners of board and change all the '#'s to 'o's as they are the one that cant be flipped , and change all the remaining 'o's to 'x's as they are ones that can be fipped