//
//  Module.hpp
//  AeonNodeEditor
//
//  Created by Akira Matsuda on 3/10/16.
//
//

#ifndef Module_hpp
#define Module_hpp

#include <string>
#include <vector>
#include "ofEventUtils.h"
#include "ofxDatGui.h"
#include "ModuleCore.hpp"
#include "thunderclap.h"

namespace AeonKitMapper {
	template <typename T> class Module : public ModuleCore {
	protected:
		ofxDatGui *gui;
		
		virtual void onMouseDragged(ofMouseEventArgs& mouseArgs) override;
	public:
		virtual void connected(AeonNode::Connector *to) override {
			this->eval_and_send();
		}
		virtual void size_to_fit() override;
		void update(ofEventArgs &args);
		Module(std::string module_name, float x, float y);
		~Module();
		virtual void add_connector(std::string tag, std::type_info *connectable_type, AeonNode::Connector::Type type) override;
		virtual void received_data(AeonNode::Node *from, AeonNode::Connector *connector, boost::any data) override = 0;
		virtual T eval() = 0;
		virtual void eval_and_send() = 0;
		virtual T update_output_state() = 0;
	};
}

#include "detail/Module.hpp"

#endif /* Module_hpp */
