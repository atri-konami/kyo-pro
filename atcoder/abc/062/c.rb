h,w=gets.chomp.split.map(&:to_i)
if h%3 == 0 || w%3 == 0
    puts 0
    exit 0
end
s2 = 0
s1 = [h,w].min
if h.even? && w.even?
    s2 = [s1, h*w/4].min
elsif h.odd? && w.odd?
    n = (h-1)/2
    m = (w-1)/2
    s2 = [s1, (n*w)-(n+1)*m, (m*h)-(m+1)*n].min
elsif h.even?
    n = h/2
    m = (w-1)/2
    s2 = [s1, h*m-(m+1)*n].min
else
    n = w/2
    m = (h-1)/2
    s2 = [s1, w*m-(m+1)*n].min
end
puts s2

