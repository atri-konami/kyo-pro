s = gets.chomp
t = gets.to_i
now = [0,0]
cnt = 0
s.each_char{|c|
    case c
    when 'L'
        now[0] -= 1
    when 'R'
        now[0] += 1
    when 'U'
        now[1] += 1
    when 'D'
        now[1] -= 1
    when '?'
        cnt += 1
    end
}

d = now[0].abs + now[1].abs

if t == 1
    puts d + cnt
else 
    if d >= cnt
        puts d-cnt
    else
        puts (cnt-d)%2
    end
end
