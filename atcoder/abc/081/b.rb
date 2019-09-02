n = gets.chomp.to_i
a = gets.chomp.split.map(&:to_i)

c = 1
loop do
    d = 2 ** c
    if a.any?{|ai| ai % d != 0}
        puts c - 1
        break
    end
    c += 1
end
