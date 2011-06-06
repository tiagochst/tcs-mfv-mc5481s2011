\* Problem: nd30 *\

Minimize
 totalcost: + y(1,2) + y(3,2) + y(2,4) + y(1,3) + 4 y(3,4) + y(4,5)

Subject To
 is_path(2): + y(1,2) + y(3,2) - y(2,4) = -0
 is_path(3): - y(3,2) + y(1,3) - y(3,4) = -0
 is_path(4): + y(2,4) + y(3,4) - y(4,5) = -0
 outcoming_s: + y(1,2) + y(1,3) = 1
 incoming_t: + y(4,5) = 1
 sa_weight: + 2 y(1,2) + y(3,2) + y(2,4) + 2 y(1,3) + 2 y(3,4)
 + 2 y(4,5) <= 10

Bounds
 0 <= y(1,2) <= 1
 0 <= y(3,2) <= 1
 0 <= y(2,4) <= 1
 0 <= y(1,3) <= 1
 0 <= y(3,4) <= 1
 0 <= y(4,5) <= 1

Generals
 y(1,2)
 y(3,2)
 y(2,4)
 y(1,3)
 y(3,4)
 y(4,5)

End
