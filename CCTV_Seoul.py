import pandas as pd
import numpy as np

CCTV_Seoul = pd.read_csv('../data/01. CCTV_in_Seoul.csv', encoding='utf-8')
CCTV_Seoul.rename(columns={CCTV_Seoul.columns[0] : '구별'}, inplace=True)

pop_Seoul = pd.read_excel('../data/01. population_in_Seoul.xls', header = 2, usecols = 'B, D, G, J, N', encoding='utf-8')
pop_Seoul.rename(columns = {pop_Seoul.columns[0] : '구별',
                            pop_Seoul.columns[1] : '인구수',
                            pop_Seoul.columns[2] : '한국인',
                            pop_Seoul.columns[3] : '외국인',
                            pop_Seoul.columns[4] : '고령자'}, inplace = True)

CCTV_Seoul['최근증가율'] = (CCTV_Seoul['2016년'] + CCTV_Seoul['2015년'] + CCTV_Seoul['2014년']) / CCTV_Seoul['2013년도 이전'] * 100
pop_Seoul.drop([0], inplace = True)

# pop_Seoul['구별'].unique()
# pop_Seoul[pop_Seoul['구별'].isnull()]
pop_Seoul.drop([26], inplace = True)

data_result = pd.merge(CCTV_Seoul, pop_Seoul, on = '구별')
# data_result.head()

del data_result['2013년도 이전']
del data_result['2014년']
del data_result['2015년']
del data_result['2016년']
# data_result.head()

data_result.set_index('구별', inplace = True)

# 상관관계가 0.1 이하면 의미없는 데이터, 0.3은 보통, 0.7이상이면 필연적인 관계가 존재함.
# np.corrcoef(data_result['인구수'], data_result['소계'])

# 오차별로 colormap을 표시, 산점도, 직선 표현 & 산점도에 대응되는 구 이름을 추가하는 코드
# data_result.shape
# x축 데이터 생성
fx = np.linspace(100000, 700000, 100)

# 1차 방정식 계수 생성 및 1차 함수 클래스 생성
fp1 = np.polyfit(data_result['인구수'], data_result['소계'], 1)
f1 = np.poly1d(fp1)

# 오차 계산
data_result['오차'] = np.abs(f1(data_result['인구수']) - data_result['소계'])

# 산점도, 직선 표현 & 오찻값에 따른 colormap 생성
plt.scatter(data_result['인구수'], data_result['소계'], c = data_result['오차'], s=50)
plt.plot(fx, f1(fx), ls='dashed', lw=3, color='g')

# 산점도에 대응되는 구 이름을 
for idx in range(0,25):
    plt.text(df_sort['인구수'][idx] * 1.02, df_sort['소계'][idx] * 0.98, df_sort.index[idx], fontsize = 15)
    
plt.xlabel('인구수')
plt.ylabel('인구당비율')
plt.colorbar()
plt.grid()
plt.show()
