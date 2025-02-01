null :: [a] -> Bool
null [] = True
null _ = False

-- Task A-3:

-- Here are two "other" definitions of null. Why are they both worse 
-- than the definition via pattern matching you've hopefully defined
-- above?

-- null2 xs = xs == []
-- null3 xs = length xs == 0

-- PLEASE ANSWER THE QUESTION HERE