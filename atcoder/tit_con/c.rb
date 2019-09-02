s=gets.chomp
while s!=(t=s.sub(/oo(o*)(okayama)/){|w|
    v=w
    while v!=(t=v.sub(/oo/){"O"}.sub(/OO/){"o"}) do
        v=t
    end
    v
}) do
    s=t
end;

puts t
