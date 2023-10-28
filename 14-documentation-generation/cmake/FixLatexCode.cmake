# Replace LaTeX code in the generated files
file(READ index.tex FILE_CONTENTS)
# Original image size:
#string(REGEX REPLACE "\\\\includegraphics\\[height=\\\\baselineskip,keepaspectratio=true\\]" "\\\\includegraphics[scale=1]" MODIFIED_CONTENTS "${FILE_CONTENTS}")

# 70% Original image size:
#string(REGEX REPLACE "\\\\includegraphics\\[height=\\\\baselineskip,keepaspectratio=true\\]" "\\\\includegraphics[scale=0.7]" MODIFIED_CONTENTS "${FILE_CONTENTS}")

# Use 100% of page width
string(REGEX REPLACE "\\\\includegraphics\\[height=\\\\baselineskip,keepaspectratio=true\\]" "\\\\includegraphics[width=\\\\textwidth,keepaspectratio=true]" MODIFIED_CONTENTS "${FILE_CONTENTS}")

# Use 70% of page width
#string(REGEX REPLACE "\\\\includegraphics\\[height=\\\\baselineskip,keepaspectratio=true\\]" "\\\\includegraphics[width=0.7\\\\textwidth,keepaspectratio=true]" MODIFIED_CONTENTS "${FILE_CONTENTS}")

file(WRITE index.tex "${MODIFIED_CONTENTS}")
