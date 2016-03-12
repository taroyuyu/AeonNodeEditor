//
//  ConditionModule.hpp
//  AeonNodeEditor
//
//  Created by Akira Matsuda on 3/12/16.
//
//

#ifndef ConditionModule_hpp
#define ConditionModule_hpp

#include "../Module.hpp"

namespace AeonKitMapper {
	template <typename T> class ConditionModule : public Module<bool> {
	public:
		typedef enum {
			Equal,
			NotEqual,
			Grater,
			GraterThan,
			Less,
			LessThan,
		} ComparisonType;
	private:
		T in1;
		T in2;
		ofxDatGuiButton *comparison_type_button;
		static std::string comparison_type_text(ComparisonType type) {
			std::string result = "";
			switch (type) {
				case Equal: {
					result = "== : Equal";
				}
					break;
				case NotEqual: {
					result = "!= : NotEqual";
				}
					break;
				case Grater: {
					result = "> : Grater";
				}
					break;
				case GraterThan: {
					result = ">= : GraterThan";
				}
					break;
				case Less: {
					result = "< : Less";
				}
					break;
				case LessThan: {
					result = "<= : LessThan";
				}
					break;
			}
			
			return result;
		}
		void onButtonEvent(ofxDatGuiButtonEvent e);
	public:
		ConditionModule(float x, float y);
		ComparisonType type;
		void switch_comparison_type();
		virtual void received_data(AeonNode::Node *from, AeonNode::Connector *connector, boost::any data) override;
		virtual bool eval() override;
		virtual void eval_and_send() override;
		virtual bool update_output_state() override;
	};
}

#include "detail/ConditionModule.hpp"

#endif /* ConditionModule_hpp */
