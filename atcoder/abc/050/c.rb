mod = 1000000007
n = gets.to_i
a = gets.chomp.split.map(&:to_i).sort

s = (n+1) % 2
i = 0

if s == 0
    if s != a[i]
        puts 0
        exit 0
    end

    i += 1
    s += 2
end

while i < n-1
    if s == a[i] && a[i] == a[i+1]
        i += 2
        s += 2
        next
    end

    puts 0
    exit 0
end

res = 1

1.upto(n/2) do
    res = res * 2 % mod
end

puts res
