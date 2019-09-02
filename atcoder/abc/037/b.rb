n,q=gets.chomp.split.map(&:to_i)

arr=Array.new(n, 0)

q.times do
    l,r,t = gets.chomp.split.map(&:to_i)
    (l-1...r).each do |idx|
        arr[idx] = t
    end
end

arr.each do |x|
    puts x
end
