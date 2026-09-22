class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        operators = {'+', '-', '*', '/'}
        for i in range(len(tokens)):
            if(tokens[i] in operators):
                if len(st) > 1:
                    first = st.pop()
                    second = st.pop()
                    if(tokens[i] == '+'):
                        st.append(first+second)
                    elif(tokens[i] == '-'):
                        st.append(second-first)
                    elif(tokens[i] == '*'):
                        st.append(first*second)
                    elif(tokens[i] == '/'):
                        st.append(int(second / first))
            else:
                st.append(int(tokens[i]))
        return st.pop()