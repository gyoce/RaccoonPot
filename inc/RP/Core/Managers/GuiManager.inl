template<class T, typename ...Args>
std::shared_ptr<T> RP::GuiManager::CreateWidget(Args&&... args) {
    return std::make_shared<T>(std::forward<Args>(args)...);
}