n,a,b = gets.chomp.split.map(&:to_i)
f = 0
bf = 0

gets.chomp.split('').each{|x|
    if x == 'a'
        if f < a+b
            f += 1
            puts 'Yes'
        else
            puts 'No'
        end
    elsif x == 'b'
        if f < a+b && bf < b
            f += 1
            bf += 1
            puts 'Yes'
        else
            puts 'No'
        end
    else
        puts 'No'
    end
}
