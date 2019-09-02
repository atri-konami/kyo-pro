n,y = gets.chomp.split.map(&:to_i)

for i in 0..n do
    for j in 0..(n-i) do
        k = n-i-j
        if 10000 * i + 5000 * j + 1000 * k == y
            puts "#{i} #{j} #{k}"
            exit
        end
    end
end

puts "-1 -1 -1"
