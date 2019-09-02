a,b,c,x = Array.new(4){|i| gets.chomp.to_i}

count = 0
for i in 0..a
    for j in 0..b do
        for k in 0..c do
            d = 500 * i + 100 * j + 50 * k
            count += 1 if d == x
        end
    end
end

puts count
