import UIKit

/// This delegate forces popover presentation even on iPhone / in compact size classes
class ForcePopoverPresenter: NSObject, UIPopoverPresentationControllerDelegate {
    static let presenter = ForcePopoverPresenter()

    private static let verticalPadding: CGFloat = 10

    /// Configures a view controller to use a popover presentation style
    static func configurePresentationControllerForViewController(controller: UIViewController, presentingFromView sourceView: UIView) {
        controller.modalPresentationStyle = .Popover

        let presentationController = controller.popoverPresentationController
        presentationController?.permittedArrowDirections = .Any
        presentationController?.sourceView = sourceView

        // Outset the source rect vertically to push the popover up / down a little
        // when displayed. Otherwise, when presented from a navigation controller
        // the top of the popover lines up perfectly with the bottom of the
        // navigation controller and looks a little odd
        presentationController?.sourceRect = CGRectInset(sourceView.bounds, 0, -verticalPadding)
        presentationController?.delegate = ForcePopoverPresenter.presenter

        controller.view.sizeToFit()
    }

    func adaptivePresentationStyleForPresentationController(controller: UIPresentationController, traitCollection: UITraitCollection) -> UIModalPresentationStyle {
        return .None
    }
}
