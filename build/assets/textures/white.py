from PIL import Image

# 定义图像大小
width = 200
height = 600

# 创建白色底图像
image = Image.new("RGB", (width, height), "white")

# 保存图像
image.save("white.png")

print("白色長方底圖片已經生成。")

