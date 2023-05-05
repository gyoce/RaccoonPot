#ifndef RP_MACROS_HPP
#define RP_MACROS_HPP

#define RP_SCENE_CONSTRUCTOR(SceneName) explicit SceneName(SDL_Renderer* renderer): Scene(renderer)

#define RP_DELETE_MISC_CONSTRUCTORS(ClassName)\
    ClassName(ClassName& other) = delete; \
    ClassName(ClassName&& other) = delete; \
    ClassName& operator=(const ClassName& other) = delete; \
    ClassName& operator=(ClassName&& other) = delete;

#endif // RP_MACROS_HPP