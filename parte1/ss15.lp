\* Problem: ss15 *\

Minimize
 time_accomplished: + end(1,4) + end(2,4) + end(3,4)

Subject To
 only_one_order(1,2): + x(1,2) + x(2,1) = 1
 only_one_order(1,3): + x(1,3) + x(3,1) = 1
 only_one_order(2,1): + x(1,2) + x(2,1) = 1
 only_one_order(2,3): + x(2,3) + x(3,2) = 1
 only_one_order(3,1): + x(1,3) + x(3,1) = 1
 only_one_order(3,2): + x(2,3) + x(3,2) = 1
 min(1,1): + end(1,1) >= 1
 min(1,2): + end(1,2) >= 1
 min(1,3): + end(1,3) >= 1
 min(1,4): + end(1,4) >= 1
 min(2,1): + end(2,1) >= 1
 min(2,2): + end(2,2) >= 1
 min(2,3): + end(2,3) >= 1
 min(2,4): + end(2,4) >= 1
 min(3,1): + end(3,1) >= 1
 min(3,2): + end(3,2) >= 1
 min(3,3): + end(3,3) >= 2
 min(3,4): + end(3,4) >= 2
 time(1,2): - end(1,1) + end(1,2) >= 1
 time(1,3): - end(1,2) + end(1,3) >= 1
 time(1,4): - end(1,3) + end(1,4) >= 1
 time(2,2): - end(2,1) + end(2,2) >= 1
 time(2,3): - end(2,2) + end(2,3) >= 1
 time(2,4): - end(2,3) + end(2,4) >= 1
 time(3,2): - end(3,1) + end(3,2) >= 1
 time(3,3): - end(3,2) + end(3,3) >= 2
 time(3,4): - end(3,3) + end(3,4) >= 2
 time2(2,1): - end(1,1) + end(2,1) >= 1
 time2(2,2): - end(1,2) + end(2,2) >= 1
 time2(2,3): - end(1,3) + end(2,3) >= 1
 time2(2,4): - end(1,4) + end(2,4) >= 1
 time2(3,1): - end(2,1) + end(3,1) >= 1
 time2(3,2): - end(2,2) + end(3,2) >= 1
 time2(3,3): - end(2,3) + end(3,3) >= 2
 time2(3,4): - end(2,4) + end(3,4) >= 2

Bounds
 0 <= x(1,2) <= 1
 0 <= x(2,1) <= 1
 0 <= x(1,3) <= 1
 0 <= x(3,1) <= 1
 0 <= x(2,3) <= 1
 0 <= x(3,2) <= 1

Generals
 x(1,2)
 x(2,1)
 x(1,3)
 x(3,1)
 x(2,3)
 x(3,2)
 end(1,1)
 end(1,2)
 end(1,3)
 end(1,4)
 end(2,1)
 end(2,2)
 end(2,3)
 end(2,4)
 end(3,1)
 end(3,2)
 end(3,3)
 end(3,4)

End
