\* Problem: mn22 *\

Minimize
 cost_transp: + rdiff(1,1) + rdiff(1,2) + rdiff(2,3) + rdiff(2,4)
 + rdiff(2,5) + 5 rdiff(3,2) + rdiff(3,4) + rdiff(3,6)

Subject To
 nroom(1): + x(1,1) + x(1,2) + x(1,3) = 1
 nroom(2): + x(2,1) + x(2,2) + x(2,3) = 1
 nroom(3): + x(3,1) + x(3,2) + x(3,3) = 1
 nproom(1): + y(1,1) + y(1,2) + y(1,3) = 1
 nproom(2): + y(2,1) + y(2,2) + y(2,3) = 1
 nproom(3): + y(3,1) + y(3,2) + y(3,3) = 1
 nproom(4): + y(4,1) + y(4,2) + y(4,3) = 1
 nproom(5): + y(5,1) + y(5,2) + y(5,3) = 1
 nproom(6): + y(6,1) + y(6,2) + y(6,3) = 1
 sameroom(1,1,1): - x(1,1) + y(1,1) + rdiff(1,1) >= -0
 sameroom(1,1,2): - x(1,2) + y(1,2) + rdiff(1,1) >= -0
 sameroom(1,1,3): - x(1,3) + y(1,3) + rdiff(1,1) >= -0
 sameroom(1,2,1): - x(1,1) + y(2,1) + rdiff(1,2) >= -0
 sameroom(1,2,2): - x(1,2) + y(2,2) + rdiff(1,2) >= -0
 sameroom(1,2,3): - x(1,3) + y(2,3) + rdiff(1,2) >= -0
 sameroom(1,3,1): - x(1,1) + y(3,1) + rdiff(1,3) >= -0
 sameroom(1,3,2): - x(1,2) + y(3,2) + rdiff(1,3) >= -0
 sameroom(1,3,3): - x(1,3) + y(3,3) + rdiff(1,3) >= -0
 sameroom(1,4,1): - x(1,1) + y(4,1) + rdiff(1,4) >= -0
 sameroom(1,4,2): - x(1,2) + y(4,2) + rdiff(1,4) >= -0
 sameroom(1,4,3): - x(1,3) + y(4,3) + rdiff(1,4) >= -0
 sameroom(1,5,1): - x(1,1) + y(5,1) + rdiff(1,5) >= -0
 sameroom(1,5,2): - x(1,2) + y(5,2) + rdiff(1,5) >= -0
 sameroom(1,5,3): - x(1,3) + y(5,3) + rdiff(1,5) >= -0
 sameroom(1,6,1): - x(1,1) + y(6,1) + rdiff(1,6) >= -0
 sameroom(1,6,2): - x(1,2) + y(6,2) + rdiff(1,6) >= -0
 sameroom(1,6,3): - x(1,3) + y(6,3) + rdiff(1,6) >= -0
 sameroom(2,1,1): - x(2,1) + y(1,1) + rdiff(2,1) >= -0
 sameroom(2,1,2): - x(2,2) + y(1,2) + rdiff(2,1) >= -0
 sameroom(2,1,3): - x(2,3) + y(1,3) + rdiff(2,1) >= -0
 sameroom(2,2,1): - x(2,1) + y(2,1) + rdiff(2,2) >= -0
 sameroom(2,2,2): - x(2,2) + y(2,2) + rdiff(2,2) >= -0
 sameroom(2,2,3): - x(2,3) + y(2,3) + rdiff(2,2) >= -0
 sameroom(2,3,1): - x(2,1) + y(3,1) + rdiff(2,3) >= -0
 sameroom(2,3,2): - x(2,2) + y(3,2) + rdiff(2,3) >= -0
 sameroom(2,3,3): - x(2,3) + y(3,3) + rdiff(2,3) >= -0
 sameroom(2,4,1): - x(2,1) + y(4,1) + rdiff(2,4) >= -0
 sameroom(2,4,2): - x(2,2) + y(4,2) + rdiff(2,4) >= -0
 sameroom(2,4,3): - x(2,3) + y(4,3) + rdiff(2,4) >= -0
 sameroom(2,5,1): - x(2,1) + y(5,1) + rdiff(2,5) >= -0
 sameroom(2,5,2): - x(2,2) + y(5,2) + rdiff(2,5) >= -0
 sameroom(2,5,3): - x(2,3) + y(5,3) + rdiff(2,5) >= -0
 sameroom(2,6,1): - x(2,1) + y(6,1) + rdiff(2,6) >= -0
 sameroom(2,6,2): - x(2,2) + y(6,2) + rdiff(2,6) >= -0
 sameroom(2,6,3): - x(2,3) + y(6,3) + rdiff(2,6) >= -0
 sameroom(3,1,1): - x(3,1) + y(1,1) + rdiff(3,1) >= -0
 sameroom(3,1,2): - x(3,2) + y(1,2) + rdiff(3,1) >= -0
 sameroom(3,1,3): - x(3,3) + y(1,3) + rdiff(3,1) >= -0
 sameroom(3,2,1): - x(3,1) + y(2,1) + rdiff(3,2) >= -0
 sameroom(3,2,2): - x(3,2) + y(2,2) + rdiff(3,2) >= -0
 sameroom(3,2,3): - x(3,3) + y(2,3) + rdiff(3,2) >= -0
 sameroom(3,3,1): - x(3,1) + y(3,1) + rdiff(3,3) >= -0
 sameroom(3,3,2): - x(3,2) + y(3,2) + rdiff(3,3) >= -0
 sameroom(3,3,3): - x(3,3) + y(3,3) + rdiff(3,3) >= -0
 sameroom(3,4,1): - x(3,1) + y(4,1) + rdiff(3,4) >= -0
 sameroom(3,4,2): - x(3,2) + y(4,2) + rdiff(3,4) >= -0
 sameroom(3,4,3): - x(3,3) + y(4,3) + rdiff(3,4) >= -0
 sameroom(3,5,1): - x(3,1) + y(5,1) + rdiff(3,5) >= -0
 sameroom(3,5,2): - x(3,2) + y(5,2) + rdiff(3,5) >= -0
 sameroom(3,5,3): - x(3,3) + y(5,3) + rdiff(3,5) >= -0
 sameroom(3,6,1): - x(3,1) + y(6,1) + rdiff(3,6) >= -0
 sameroom(3,6,2): - x(3,2) + y(6,2) + rdiff(3,6) >= -0
 sameroom(3,6,3): - x(3,3) + y(6,3) + rdiff(3,6) >= -0
 room_limit(1): + x(1,1) + x(2,1) + x(3,1) <= 2
 room_limit(2): + x(1,2) + x(2,2) + x(3,2) <= 2
 room_limit(3): + x(1,3) + x(2,3) + x(3,3) <= 2

Bounds
 0 <= x(1,1) <= 1
 0 <= x(1,2) <= 1
 0 <= x(1,3) <= 1
 0 <= x(2,1) <= 1
 0 <= x(2,2) <= 1
 0 <= x(2,3) <= 1
 0 <= x(3,1) <= 1
 0 <= x(3,2) <= 1
 0 <= x(3,3) <= 1
 0 <= y(1,1) <= 1
 0 <= y(1,2) <= 1
 0 <= y(1,3) <= 1
 0 <= y(2,1) <= 1
 0 <= y(2,2) <= 1
 0 <= y(2,3) <= 1
 0 <= y(3,1) <= 1
 0 <= y(3,2) <= 1
 0 <= y(3,3) <= 1
 0 <= y(4,1) <= 1
 0 <= y(4,2) <= 1
 0 <= y(4,3) <= 1
 0 <= y(5,1) <= 1
 0 <= y(5,2) <= 1
 0 <= y(5,3) <= 1
 0 <= y(6,1) <= 1
 0 <= y(6,2) <= 1
 0 <= y(6,3) <= 1
 -1 <= rdiff(1,1) <= 1
 -1 <= rdiff(1,2) <= 1
 -1 <= rdiff(1,3) <= 1
 -1 <= rdiff(1,4) <= 1
 -1 <= rdiff(1,5) <= 1
 -1 <= rdiff(1,6) <= 1
 -1 <= rdiff(2,1) <= 1
 -1 <= rdiff(2,2) <= 1
 -1 <= rdiff(2,3) <= 1
 -1 <= rdiff(2,4) <= 1
 -1 <= rdiff(2,5) <= 1
 -1 <= rdiff(2,6) <= 1
 -1 <= rdiff(3,1) <= 1
 -1 <= rdiff(3,2) <= 1
 -1 <= rdiff(3,3) <= 1
 -1 <= rdiff(3,4) <= 1
 -1 <= rdiff(3,5) <= 1
 -1 <= rdiff(3,6) <= 1

Generals
 x(1,1)
 x(1,2)
 x(1,3)
 x(2,1)
 x(2,2)
 x(2,3)
 x(3,1)
 x(3,2)
 x(3,3)
 y(1,1)
 y(1,2)
 y(1,3)
 y(2,1)
 y(2,2)
 y(2,3)
 y(3,1)
 y(3,2)
 y(3,3)
 y(4,1)
 y(4,2)
 y(4,3)
 y(5,1)
 y(5,2)
 y(5,3)
 y(6,1)
 y(6,2)
 y(6,3)
 rdiff(1,1)
 rdiff(1,2)
 rdiff(1,3)
 rdiff(1,4)
 rdiff(1,5)
 rdiff(1,6)
 rdiff(2,1)
 rdiff(2,2)
 rdiff(2,3)
 rdiff(2,4)
 rdiff(2,5)
 rdiff(2,6)
 rdiff(3,1)
 rdiff(3,2)
 rdiff(3,3)
 rdiff(3,4)
 rdiff(3,5)
 rdiff(3,6)

End
