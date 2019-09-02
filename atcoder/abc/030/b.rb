n,m=gets.chomp.split.map(&:to_i);n=(n>12 ? n-12 : n);dn=n*30+30*(m/60.0);dm=m*6.0;d=(dn-dm).abs;puts [d,360-d].min
