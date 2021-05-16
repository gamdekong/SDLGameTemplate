#pragma once
#ifndef __SCENE__
#define __SCENE__

#include "GameObject.h"
#include "DisplayObject.h"
#include <optional>
#include <vector>


class Scene : public GameObject
{
public:
	friend class DisplayObject;
	Scene() = default;
	virtual ~Scene() override;
	virtual void draw() override = 0;
	virtual void update() override = 0;
	virtual void clean() override = 0;
	virtual void handleEvents() = 0;
	virtual void start() = 0;

	void addChild(DisplayObject* child, uint32_t layer_index = 0, std::optional<uint32_t> order_index = std::nullopt);
	void removeChild(DisplayObject* child);

	void removeAllChildren();
	int numberOfChildren() const;

	void updateDisplayList();
	void drawDisplayList();

	std::vector<DisplayObject*> getDisplayList() const;

private:
	uint32_t m_nextLayerIndex;
	std::vector<DisplayObject*> m_displayList;

	static bool sortObjects(DisplayObject* left, DisplayObject* right);
};


#endif // !__SCENE__

