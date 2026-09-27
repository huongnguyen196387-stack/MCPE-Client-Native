# MCPE Native Client Project (Android)

Dự án Client tùy biến cho MCPE (Minecraft Bedrock Edition) trên Android, sử dụng C++ NDK, ImGui và Dobby Hook.

## 🚀 Các tính năng tích hợp sẵn (Features)
- **Visuals:** Fullbright (Gamma 1000), Custom Zoom FOV, Motion Blur, Freelook 360.
- **Combat / PvP:** Auto Clicker (Chỉnh CPS), Triggerbot, Fast Place.
- **HUD & UI:** Keystrokes Display, Live CPS Counter, Armor Status, FPS Display.
- **Performance:** Smart Entity Render Culling, Particle Limiter, FPS Uncap / VSync Toggle.

## 🛠 Hướng dẫn Build trên GitHub Actions
1. Push toàn bộ thư mục dự án này lên GitHub Repository của bạn.
2. Truy cập tab **Actions** trên GitHub.
3. Chờ tiến trình build hoàn tất và tải tệp `libclient-arm64.zip` chứa `libclient.so` từ mục **Artifacts**.
