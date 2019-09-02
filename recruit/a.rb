def ok(a, n)
    a.split('').all?{|x| x.to_i < n}
end

x = gets.chomp
y = gets.chomp
z = gets.chomp.to_i

for i in 2..10 do
    for j in 2..10 do
        if (ok(x,i) && ok(y,j) && x.to_i(i) + y.to_i(j) == z)
            puts "#{i} #{j}"
            exit
        end
    end
end


