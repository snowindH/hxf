program ex01234
implicit none 
real (kind = 4)::a,b,c,dta
real(kind = 4)::root1,root2
a = 1
b = 3
c = -5.6

root1 = (-b + sqrt(b**2 - 4*a*c))/(2*a)
root2 = (-b - sqrt(b**2 - 4*a*c))/(2*a)

write(*,*)'x1 is :',root1
write(*,*)'x2 is :',root2

end
