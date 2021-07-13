date = input().split('-')
months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November',
          'December']
d = dict(Aries=[('March', 21), ('April', 19)], Taurus=[('April', 20), ('May', 20)], Gemini=[('May', 21), ('June', 20)],
         Cancer=[('June', 21), ('July', 22)], Leo=[('July', 23), ('August', 22)],
         Virgo=[('August', 23), ('September', 22)], Libra=[('September', 23), ('October', 22)],
         Scorpio=[('October', 23), ('November', 22)], Sagittarius=[('November', 23), ('December', 21)],
         Capricorn=[('December', 22), ('January', 19)], Aquarius=[('January', 20), ('February', 18)],
         Pisces=[('February', 19), ('March', 20)])

m = date[1]
day = int(date[2])
for k, v in d.items():
    if (months.index(v[0][0]) == int(m) - 1 and v[0][1] <= day) or (
            int(m) - 1 == months.index(v[1][0]) and day <= v[1][1]):
        print(k)
        break