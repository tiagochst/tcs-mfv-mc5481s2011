\* Problem: ss15 *\

Minimize
 time_accomplished: + fim

Subject To
 only_one_order(1,2): + x(1,2) + x(2,1) = 1
 only_one_order(1,3): + x(1,3) + x(3,1) = 1
 only_one_order(1,4): + x(1,4) + x(4,1) = 1
 only_one_order(1,5): + x(1,5) + x(5,1) = 1
 only_one_order(1,6): + x(1,6) + x(6,1) = 1
 only_one_order(1,7): + x(1,7) + x(7,1) = 1
 only_one_order(1,8): + x(1,8) + x(8,1) = 1
 only_one_order(1,9): + x(1,9) + x(9,1) = 1
 only_one_order(1,10): + x(1,10) + x(10,1) = 1
 only_one_order(2,1): + x(1,2) + x(2,1) = 1
 only_one_order(2,3): + x(2,3) + x(3,2) = 1
 only_one_order(2,4): + x(2,4) + x(4,2) = 1
 only_one_order(2,5): + x(2,5) + x(5,2) = 1
 only_one_order(2,6): + x(2,6) + x(6,2) = 1
 only_one_order(2,7): + x(2,7) + x(7,2) = 1
 only_one_order(2,8): + x(2,8) + x(8,2) = 1
 only_one_order(2,9): + x(2,9) + x(9,2) = 1
 only_one_order(2,10): + x(2,10) + x(10,2) = 1
 only_one_order(3,1): + x(1,3) + x(3,1) = 1
 only_one_order(3,2): + x(2,3) + x(3,2) = 1
 only_one_order(3,4): + x(3,4) + x(4,3) = 1
 only_one_order(3,5): + x(3,5) + x(5,3) = 1
 only_one_order(3,6): + x(3,6) + x(6,3) = 1
 only_one_order(3,7): + x(3,7) + x(7,3) = 1
 only_one_order(3,8): + x(3,8) + x(8,3) = 1
 only_one_order(3,9): + x(3,9) + x(9,3) = 1
 only_one_order(3,10): + x(3,10) + x(10,3) = 1
 only_one_order(4,1): + x(1,4) + x(4,1) = 1
 only_one_order(4,2): + x(2,4) + x(4,2) = 1
 only_one_order(4,3): + x(3,4) + x(4,3) = 1
 only_one_order(4,5): + x(4,5) + x(5,4) = 1
 only_one_order(4,6): + x(4,6) + x(6,4) = 1
 only_one_order(4,7): + x(4,7) + x(7,4) = 1
 only_one_order(4,8): + x(4,8) + x(8,4) = 1
 only_one_order(4,9): + x(4,9) + x(9,4) = 1
 only_one_order(4,10): + x(4,10) + x(10,4) = 1
 only_one_order(5,1): + x(1,5) + x(5,1) = 1
 only_one_order(5,2): + x(2,5) + x(5,2) = 1
 only_one_order(5,3): + x(3,5) + x(5,3) = 1
 only_one_order(5,4): + x(4,5) + x(5,4) = 1
 only_one_order(5,6): + x(5,6) + x(6,5) = 1
 only_one_order(5,7): + x(5,7) + x(7,5) = 1
 only_one_order(5,8): + x(5,8) + x(8,5) = 1
 only_one_order(5,9): + x(5,9) + x(9,5) = 1
 only_one_order(5,10): + x(5,10) + x(10,5) = 1
 only_one_order(6,1): + x(1,6) + x(6,1) = 1
 only_one_order(6,2): + x(2,6) + x(6,2) = 1
 only_one_order(6,3): + x(3,6) + x(6,3) = 1
 only_one_order(6,4): + x(4,6) + x(6,4) = 1
 only_one_order(6,5): + x(5,6) + x(6,5) = 1
 only_one_order(6,7): + x(6,7) + x(7,6) = 1
 only_one_order(6,8): + x(6,8) + x(8,6) = 1
 only_one_order(6,9): + x(6,9) + x(9,6) = 1
 only_one_order(6,10): + x(6,10) + x(10,6) = 1
 only_one_order(7,1): + x(1,7) + x(7,1) = 1
 only_one_order(7,2): + x(2,7) + x(7,2) = 1
 only_one_order(7,3): + x(3,7) + x(7,3) = 1
 only_one_order(7,4): + x(4,7) + x(7,4) = 1
 only_one_order(7,5): + x(5,7) + x(7,5) = 1
 only_one_order(7,6): + x(6,7) + x(7,6) = 1
 only_one_order(7,8): + x(7,8) + x(8,7) = 1
 only_one_order(7,9): + x(7,9) + x(9,7) = 1
 only_one_order(7,10): + x(7,10) + x(10,7) = 1
 only_one_order(8,1): + x(1,8) + x(8,1) = 1
 only_one_order(8,2): + x(2,8) + x(8,2) = 1
 only_one_order(8,3): + x(3,8) + x(8,3) = 1
 only_one_order(8,4): + x(4,8) + x(8,4) = 1
 only_one_order(8,5): + x(5,8) + x(8,5) = 1
 only_one_order(8,6): + x(6,8) + x(8,6) = 1
 only_one_order(8,7): + x(7,8) + x(8,7) = 1
 only_one_order(8,9): + x(8,9) + x(9,8) = 1
 only_one_order(8,10): + x(8,10) + x(10,8) = 1
 only_one_order(9,1): + x(1,9) + x(9,1) = 1
 only_one_order(9,2): + x(2,9) + x(9,2) = 1
 only_one_order(9,3): + x(3,9) + x(9,3) = 1
 only_one_order(9,4): + x(4,9) + x(9,4) = 1
 only_one_order(9,5): + x(5,9) + x(9,5) = 1
 only_one_order(9,6): + x(6,9) + x(9,6) = 1
 only_one_order(9,7): + x(7,9) + x(9,7) = 1
 only_one_order(9,8): + x(8,9) + x(9,8) = 1
 only_one_order(9,10): + x(9,10) + x(10,9) = 1
 only_one_order(10,1): + x(1,10) + x(10,1) = 1
 only_one_order(10,2): + x(2,10) + x(10,2) = 1
 only_one_order(10,3): + x(3,10) + x(10,3) = 1
 only_one_order(10,4): + x(4,10) + x(10,4) = 1
 only_one_order(10,5): + x(5,10) + x(10,5) = 1
 only_one_order(10,6): + x(6,10) + x(10,6) = 1
 only_one_order(10,7): + x(7,10) + x(10,7) = 1
 only_one_order(10,8): + x(8,10) + x(10,8) = 1
 only_one_order(10,9): + x(9,10) + x(10,9) = 1
 min(1,1): + end(1,1) >= 21
 min(1,2): + end(1,2) >= 2
 min(1,3): + end(1,3) >= 26
 min(1,4): + end(1,4) >= 11
 min(1,5): + end(1,5) >= 8
 min(2,1): + end(2,1) >= 12
 min(2,2): + end(2,2) >= 4
 min(2,3): + end(2,3) >= 23
 min(2,4): + end(2,4) >= 3
 min(2,5): + end(2,5) >= 24
 min(3,1): + end(3,1) >= 15
 min(3,2): + end(3,2) >= 27
 min(3,3): + end(3,3) >= 29
 min(3,4): + end(3,4) >= 2
 min(3,5): + end(3,5) >= 18
 min(4,1): + end(4,1) >= 26
 min(4,2): + end(4,2) >= 14
 min(4,3): + end(4,3) >= 24
 min(4,4): + end(4,4) >= 22
 min(4,5): + end(4,5) >= 16
 min(5,1): + end(5,1) >= 30
 min(5,2): + end(5,2) >= 11
 min(5,3): + end(5,3) >= 26
 min(5,4): + end(5,4) >= 11
 min(5,5): + end(5,5) >= 12
 min(6,1): + end(6,1) >= 15
 min(6,2): + end(6,2) >= 11
 min(6,3): + end(6,3) >= 6
 min(6,4): + end(6,4) >= 2
 min(6,5): + end(6,5) >= 27
 min(7,1): + end(7,1) >= 16
 min(7,2): + end(7,2) >= 21
 min(7,3): + end(7,3) >= 10
 min(7,4): + end(7,4) >= 29
 min(7,5): + end(7,5) >= 30
 min(8,1): + end(8,1) >= 5
 min(8,2): + end(8,2) >= 29
 min(8,3): + end(8,3) >= 12
 min(8,4): + end(8,4) >= 30
 min(8,5): + end(8,5) >= 29
 min(9,1): + end(9,1) >= 19
 min(9,2): + end(9,2) >= 11
 min(9,3): + end(9,3) >= 5
 min(9,4): + end(9,4) >= 12
 min(9,5): + end(9,5) >= 12
 min(10,1): + end(10,1) >= 21
 min(10,2): + end(10,2) >= 26
 min(10,3): + end(10,3) >= 3
 min(10,4): + end(10,4) >= 4
 min(10,5): + end(10,5) >= 17
 time(1,2): - end(1,1) + end(1,2) >= 2
 time(1,3): - end(1,2) + end(1,3) >= 26
 time(1,4): - end(1,3) + end(1,4) >= 11
 time(1,5): - end(1,4) + end(1,5) >= 8
 time(2,2): - end(2,1) + end(2,2) >= 4
 time(2,3): - end(2,2) + end(2,3) >= 23
 time(2,4): - end(2,3) + end(2,4) >= 3
 time(2,5): - end(2,4) + end(2,5) >= 24
 time(3,2): - end(3,1) + end(3,2) >= 27
 time(3,3): - end(3,2) + end(3,3) >= 29
 time(3,4): - end(3,3) + end(3,4) >= 2
 time(3,5): - end(3,4) + end(3,5) >= 18
 time(4,2): - end(4,1) + end(4,2) >= 14
 time(4,3): - end(4,2) + end(4,3) >= 24
 time(4,4): - end(4,3) + end(4,4) >= 22
 time(4,5): - end(4,4) + end(4,5) >= 16
 time(5,2): - end(5,1) + end(5,2) >= 11
 time(5,3): - end(5,2) + end(5,3) >= 26
 time(5,4): - end(5,3) + end(5,4) >= 11
 time(5,5): - end(5,4) + end(5,5) >= 12
 time(6,2): - end(6,1) + end(6,2) >= 11
 time(6,3): - end(6,2) + end(6,3) >= 6
 time(6,4): - end(6,3) + end(6,4) >= 2
 time(6,5): - end(6,4) + end(6,5) >= 27
 time(7,2): - end(7,1) + end(7,2) >= 21
 time(7,3): - end(7,2) + end(7,3) >= 10
 time(7,4): - end(7,3) + end(7,4) >= 29
 time(7,5): - end(7,4) + end(7,5) >= 30
 time(8,2): - end(8,1) + end(8,2) >= 29
 time(8,3): - end(8,2) + end(8,3) >= 12
 time(8,4): - end(8,3) + end(8,4) >= 30
 time(8,5): - end(8,4) + end(8,5) >= 29
 time(9,2): - end(9,1) + end(9,2) >= 11
 time(9,3): - end(9,2) + end(9,3) >= 5
 time(9,4): - end(9,3) + end(9,4) >= 12
 time(9,5): - end(9,4) + end(9,5) >= 12
 time(10,2): - end(10,1) + end(10,2) >= 26
 time(10,3): - end(10,2) + end(10,3) >= 3
 time(10,4): - end(10,3) + end(10,4) >= 4
 time(10,5): - end(10,4) + end(10,5) >= 17
 time2(2,1): - end(1,1) + end(2,1) >= 12
 time2(2,2): - end(1,2) + end(2,2) >= 4
 time2(2,3): - end(1,3) + end(2,3) >= 23
 time2(2,4): - end(1,4) + end(2,4) >= 3
 time2(2,5): - end(1,5) + end(2,5) >= 24
 time2(3,1): - end(2,1) + end(3,1) >= 15
 time2(3,2): - end(2,2) + end(3,2) >= 27
 time2(3,3): - end(2,3) + end(3,3) >= 29
 time2(3,4): - end(2,4) + end(3,4) >= 2
 time2(3,5): - end(2,5) + end(3,5) >= 18
 time2(4,1): - end(3,1) + end(4,1) >= 26
 time2(4,2): - end(3,2) + end(4,2) >= 14
 time2(4,3): - end(3,3) + end(4,3) >= 24
 time2(4,4): - end(3,4) + end(4,4) >= 22
 time2(4,5): - end(3,5) + end(4,5) >= 16
 time2(5,1): - end(4,1) + end(5,1) >= 30
 time2(5,2): - end(4,2) + end(5,2) >= 11
 time2(5,3): - end(4,3) + end(5,3) >= 26
 time2(5,4): - end(4,4) + end(5,4) >= 11
 time2(5,5): - end(4,5) + end(5,5) >= 12
 time2(6,1): - end(5,1) + end(6,1) >= 15
 time2(6,2): - end(5,2) + end(6,2) >= 11
 time2(6,3): - end(5,3) + end(6,3) >= 6
 time2(6,4): - end(5,4) + end(6,4) >= 2
 time2(6,5): - end(5,5) + end(6,5) >= 27
 time2(7,1): - end(6,1) + end(7,1) >= 16
 time2(7,2): - end(6,2) + end(7,2) >= 21
 time2(7,3): - end(6,3) + end(7,3) >= 10
 time2(7,4): - end(6,4) + end(7,4) >= 29
 time2(7,5): - end(6,5) + end(7,5) >= 30
 time2(8,1): - end(7,1) + end(8,1) >= 5
 time2(8,2): - end(7,2) + end(8,2) >= 29
 time2(8,3): - end(7,3) + end(8,3) >= 12
 time2(8,4): - end(7,4) + end(8,4) >= 30
 time2(8,5): - end(7,5) + end(8,5) >= 29
 time2(9,1): - end(8,1) + end(9,1) >= 19
 time2(9,2): - end(8,2) + end(9,2) >= 11
 time2(9,3): - end(8,3) + end(9,3) >= 5
 time2(9,4): - end(8,4) + end(9,4) >= 12
 time2(9,5): - end(8,5) + end(9,5) >= 12
 time2(10,1): - end(9,1) + end(10,1) >= 21
 time2(10,2): - end(9,2) + end(10,2) >= 26
 time2(10,3): - end(9,3) + end(10,3) >= 3
 time2(10,4): - end(9,4) + end(10,4) >= 4
 time2(10,5): - end(9,5) + end(10,5) >= 17
 all(1): - end(1,5) + fim >= -0
 all(2): - end(2,5) + fim >= -0
 all(3): - end(3,5) + fim >= -0
 all(4): - end(4,5) + fim >= -0
 all(5): - end(5,5) + fim >= -0
 all(6): - end(6,5) + fim >= -0
 all(7): - end(7,5) + fim >= -0
 all(8): - end(8,5) + fim >= -0
 all(9): - end(9,5) + fim >= -0
 all(10): - end(10,5) + fim >= -0

Bounds
 0 <= x(1,2) <= 1
 0 <= x(2,1) <= 1
 0 <= x(1,3) <= 1
 0 <= x(3,1) <= 1
 0 <= x(1,4) <= 1
 0 <= x(4,1) <= 1
 0 <= x(1,5) <= 1
 0 <= x(5,1) <= 1
 0 <= x(1,6) <= 1
 0 <= x(6,1) <= 1
 0 <= x(1,7) <= 1
 0 <= x(7,1) <= 1
 0 <= x(1,8) <= 1
 0 <= x(8,1) <= 1
 0 <= x(1,9) <= 1
 0 <= x(9,1) <= 1
 0 <= x(1,10) <= 1
 0 <= x(10,1) <= 1
 0 <= x(2,3) <= 1
 0 <= x(3,2) <= 1
 0 <= x(2,4) <= 1
 0 <= x(4,2) <= 1
 0 <= x(2,5) <= 1
 0 <= x(5,2) <= 1
 0 <= x(2,6) <= 1
 0 <= x(6,2) <= 1
 0 <= x(2,7) <= 1
 0 <= x(7,2) <= 1
 0 <= x(2,8) <= 1
 0 <= x(8,2) <= 1
 0 <= x(2,9) <= 1
 0 <= x(9,2) <= 1
 0 <= x(2,10) <= 1
 0 <= x(10,2) <= 1
 0 <= x(3,4) <= 1
 0 <= x(4,3) <= 1
 0 <= x(3,5) <= 1
 0 <= x(5,3) <= 1
 0 <= x(3,6) <= 1
 0 <= x(6,3) <= 1
 0 <= x(3,7) <= 1
 0 <= x(7,3) <= 1
 0 <= x(3,8) <= 1
 0 <= x(8,3) <= 1
 0 <= x(3,9) <= 1
 0 <= x(9,3) <= 1
 0 <= x(3,10) <= 1
 0 <= x(10,3) <= 1
 0 <= x(4,5) <= 1
 0 <= x(5,4) <= 1
 0 <= x(4,6) <= 1
 0 <= x(6,4) <= 1
 0 <= x(4,7) <= 1
 0 <= x(7,4) <= 1
 0 <= x(4,8) <= 1
 0 <= x(8,4) <= 1
 0 <= x(4,9) <= 1
 0 <= x(9,4) <= 1
 0 <= x(4,10) <= 1
 0 <= x(10,4) <= 1
 0 <= x(5,6) <= 1
 0 <= x(6,5) <= 1
 0 <= x(5,7) <= 1
 0 <= x(7,5) <= 1
 0 <= x(5,8) <= 1
 0 <= x(8,5) <= 1
 0 <= x(5,9) <= 1
 0 <= x(9,5) <= 1
 0 <= x(5,10) <= 1
 0 <= x(10,5) <= 1
 0 <= x(6,7) <= 1
 0 <= x(7,6) <= 1
 0 <= x(6,8) <= 1
 0 <= x(8,6) <= 1
 0 <= x(6,9) <= 1
 0 <= x(9,6) <= 1
 0 <= x(6,10) <= 1
 0 <= x(10,6) <= 1
 0 <= x(7,8) <= 1
 0 <= x(8,7) <= 1
 0 <= x(7,9) <= 1
 0 <= x(9,7) <= 1
 0 <= x(7,10) <= 1
 0 <= x(10,7) <= 1
 0 <= x(8,9) <= 1
 0 <= x(9,8) <= 1
 0 <= x(8,10) <= 1
 0 <= x(10,8) <= 1
 0 <= x(9,10) <= 1
 0 <= x(10,9) <= 1

Generals
 x(1,2)
 x(2,1)
 x(1,3)
 x(3,1)
 x(1,4)
 x(4,1)
 x(1,5)
 x(5,1)
 x(1,6)
 x(6,1)
 x(1,7)
 x(7,1)
 x(1,8)
 x(8,1)
 x(1,9)
 x(9,1)
 x(1,10)
 x(10,1)
 x(2,3)
 x(3,2)
 x(2,4)
 x(4,2)
 x(2,5)
 x(5,2)
 x(2,6)
 x(6,2)
 x(2,7)
 x(7,2)
 x(2,8)
 x(8,2)
 x(2,9)
 x(9,2)
 x(2,10)
 x(10,2)
 x(3,4)
 x(4,3)
 x(3,5)
 x(5,3)
 x(3,6)
 x(6,3)
 x(3,7)
 x(7,3)
 x(3,8)
 x(8,3)
 x(3,9)
 x(9,3)
 x(3,10)
 x(10,3)
 x(4,5)
 x(5,4)
 x(4,6)
 x(6,4)
 x(4,7)
 x(7,4)
 x(4,8)
 x(8,4)
 x(4,9)
 x(9,4)
 x(4,10)
 x(10,4)
 x(5,6)
 x(6,5)
 x(5,7)
 x(7,5)
 x(5,8)
 x(8,5)
 x(5,9)
 x(9,5)
 x(5,10)
 x(10,5)
 x(6,7)
 x(7,6)
 x(6,8)
 x(8,6)
 x(6,9)
 x(9,6)
 x(6,10)
 x(10,6)
 x(7,8)
 x(8,7)
 x(7,9)
 x(9,7)
 x(7,10)
 x(10,7)
 x(8,9)
 x(9,8)
 x(8,10)
 x(10,8)
 x(9,10)
 x(10,9)
 end(1,1)
 end(1,2)
 end(1,3)
 end(1,4)
 end(1,5)
 end(2,1)
 end(2,2)
 end(2,3)
 end(2,4)
 end(2,5)
 end(3,1)
 end(3,2)
 end(3,3)
 end(3,4)
 end(3,5)
 end(4,1)
 end(4,2)
 end(4,3)
 end(4,4)
 end(4,5)
 end(5,1)
 end(5,2)
 end(5,3)
 end(5,4)
 end(5,5)
 end(6,1)
 end(6,2)
 end(6,3)
 end(6,4)
 end(6,5)
 end(7,1)
 end(7,2)
 end(7,3)
 end(7,4)
 end(7,5)
 end(8,1)
 end(8,2)
 end(8,3)
 end(8,4)
 end(8,5)
 end(9,1)
 end(9,2)
 end(9,3)
 end(9,4)
 end(9,5)
 end(10,1)
 end(10,2)
 end(10,3)
 end(10,4)
 end(10,5)
 fim

End
