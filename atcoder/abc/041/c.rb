gets;i=0;a=gets.chomp.split.map{|x| i+=1;[i,x.to_i]}.sort{|a,b| b[1]<=>a[1]}.each{|x| puts x[0]}
