#import <UIKit/UIKit.h>
#import "CTAssetsPickerController.h"

@class AbstractPost;

extern NSString *const WPEditorNavigationRestorationID;

@protocol EditPostViewControllerDelegate <NSObject>

-(void)editPostViewDismissed;

@end

@interface EditPostViewController : UIViewController <UINavigationControllerDelegate, CTAssetsPickerControllerDelegate>

@property (nonatomic, weak) id <EditPostViewControllerDelegate> delegate;

/*
 Initialize the editor with the specified post.
 @param post The post to edit.
 */
- (id)initWithPost:(AbstractPost *)post;

/*
 Compose a new post with the last used blog.
 */
- (id)initWithDraftForLastUsedBlog;

/*
 Compose a new post with the specified properties.
 The new post will belong to the last edited blog.
 
 @param title The title of the post
 @param content The post body.
 @param tags A comma separated list of tags.
 @param image A string that is either a URL path, or a base64 encoded image. If a URL path, 
 the image will appear at the top of the post with a link pointing to the image at its original location.
 If a valid base64 encoded image is provided, the image will be treated like other media items in the app. 
 */
- (id)initWithTitle:(NSString *)title
         andContent:(NSString *)content
            andTags:(NSString *)tags
           andImage:(NSString *)image;

@end
