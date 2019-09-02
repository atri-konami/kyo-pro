def is_prime?(n)
    if n==1 || n==2
        return false
    end

    3.step(Math.sqrt(n).to_i,2){|d|
        if n%d == 0
            return false
        end
    }
    true
end

s=gets.chomp
t=s.split("").uniq
if t.size > 5
    puts -1
    exit
end

a=[1,3,5,7,9]

a.permutation(t.size){|r|
    h=Hash[*(t.zip(r).flatten)]
    p=s.split("").map{|x|h[x]}.join.to_i
    if is_prime?(p) 
        puts p
        exit
    end
}

puts -1
